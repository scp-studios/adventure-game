#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <optional>

// This is pretty self explanatory, but it basically represents a single option
// for the user to choose when a passage is presented. A single chapter can co-
// ntain multiple options.
struct ChapterOption
{
    std::string label;
    std::string fileLink;
};

// A chapter is a bit of text that contains a passage and a couple of options. 
// It is, once again, pretty simple.
struct Chapter
{
    std::string passage;
    std::map<char, ChapterOption> options;
    std::string prompt;
};

// A macro to check if a string starts with another string. You use it like th-
// is: string STARTS_WITH("start")
#define STARTS_WITH(x) .substr(0, std::string(x).length()) == x

static std::vector<std::string> splitString(std::string_view host, std::string_view separator)
{
    std::vector<std::string> result;
    
    size_t start = 0;
    size_t end = host.find(separator, start);
    
    while (end != std::string::npos)
    {
        result.push_back(std::string(host.substr(start, end - start)));
        start = end + separator.length();
        end = host.find(separator, start);
    }
    
    result.push_back(std::string(host.substr(start)));
    
    return result;
}

static Chapter processIntoChapters(std::string_view filePath)
{
    // We start by opening the file using the constructor. Since ifstream does-
    // n't support string_views, we have to use data()
    std::ifstream file(filePath.data());
    if (!file)
    {
        std::cerr << "[ERROR]: Failed to open file " << filePath << std::endl;
        return {};
    }
    
    // We define the result here so that we can set some default values.
    Chapter result = {};
    
    // We set the default prompt so that it's optional
    result.prompt = "Your Choice";
    
    // This is used so that the program knows what it's loading. I hope that y-
    // ou can figure this out yourself.
    enum class LoadMode
    {
        GLOBAL, PASSAGE, OPTIONS
    };
    
    // We put the passage inside of a stringstream, because it is very easy to
    // add stuff to it. We will obtain the string inside of the stringstream l-
    // ater on in the function.
    std::stringstream passage;
    
    // We initially put the mode on GLOBAL, which means that the function is c-
    // urrently in the global namespace.
    LoadMode loadMode = LoadMode::GLOBAL;
    
    // We read the file line by line in a while loop. This may not be the best 
    // approach, but it's what I could think of. Plus, this isn't a performance
    // intensive application anyways, so as long as it isn't extremely laggy, 
    // it should be fine.
    while (file)
    {
        // We start by reading the line
        std::string line;
        std::getline(file, line);
        
        // We check for some keywords within the passage, but only check for t-
        // hese keywords if we are still in the global namespace.
        if (loadMode == LoadMode::GLOBAL)
        {
            // Switch to passage mode if this is hit
            if (line == "$begin_passage")
            {
                loadMode = LoadMode::PASSAGE;
            }
            // Switch to options mode if this is hit
            else if (line == "$begin_options")
            {
                loadMode = LoadMode::OPTIONS;
            }
            
            // If the string starts with prompt, then we split the string
            else if (line STARTS_WITH("prompt%"))
            {
                result.prompt = line.substr(line.find_first_of('%') + 1);
            }
        }
        
        // If we are in passage mode, we read to the passage
        else if (loadMode == LoadMode::PASSAGE)
        {
            if (line == "$end_passage")
            {
                loadMode = LoadMode::GLOBAL;
            } 
            else 
            {
                passage << line << "\n";
            }
        }
        
        // If we are reading the options, we read to the options
        else if (loadMode == LoadMode::OPTIONS)
        {
            if (line == "$end_options")
            {
                loadMode = LoadMode::GLOBAL;
            } 
            else 
            {
                // Check if the line actually contains a percent sign
                if (line.find_first_of('%') != std::string::npos)
                {
                    ChapterOption option = {};
                    
                    std::vector<std::string> splittedString = splitString(line, "%");
                    
                    // The first character would be the key letter.
                    option.label = splittedString[1];
                    option.fileLink = splittedString[2];
                    
                    char letter = line[0];
                    result.options.insert(std::pair<char, ChapterOption>(letter, option));
                }
                
                // If it doesn't, then don't load it as an option.
            }
        }
        
        // I think that is it for the loading. Though, it might be more compli-
        // cated than it I think.
    }
    
    // Now, we process our results and return it. All we needed to do is push
    // the passage from the stringstream to the actual string
    result.passage = passage.str();
    
    // We just return it, simple.
    return result;
}

// This function displays a chapter and asks for the user input. Then, it retu-
// rns the file that the user asked for.
static std::optional<std::string> presentChapter(const Chapter& chapter)
{
    std::cout << chapter.passage;
    
    // Check if there are any options at all.
    if (chapter.options.empty())
    {
        // If none, we return an empty optional.
        return {};
    }
    else 
    {
        for (auto& option: chapter.options)
        {
            std::cout << '[' << option.first << "] " << option.second.label << std::endl;
        }
        
        std::cout << "\n" << chapter.prompt << ": ";
        
        char useChoice;
        std::cin >> useChoice;
        
        return chapter.options.at(useChoice).fileLink;
    }
}

int main(int argc, char** argv)
{
    std::string file = "assets/test1.txt";
    
    bool continuing = true;
    while (continuing)
    {
        Chapter chapter = processIntoChapters(file);
        std::optional<std::string> nextFile = presentChapter(chapter);
        
        if (nextFile.has_value())
        {
            file = nextFile.value();
        }
        else
        {
            continuing = false;
        }
    }
}