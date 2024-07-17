# Noditto

> ditto (/ˈdɪtəʊ/) <br>
> noun - the same thing again (used in lists and accounts and often indicated by a ditto mark under the word or figure to be repeated).

Noditto is a code duplication finder program written in C++ that uses Abstract Syntax Trees (ASTs) and other algorithms to detect duplicated code blocks within a file. This tool aims to help developers identify and refactor redundant code, improving code quality and maintainability.

Features

- AST-Based Duplication Detection: Parses source code into ASTs and identifies repeated subtrees.
- Efficient Algorithms: Implements various algorithms for efficient duplication detection, including tree hashing and sliding window techniques.
- Custom Parsing: Uses a custom parser to generate ASTs, allowing for extensibility and customization.
- Detailed Reporting: Generates detailed reports on detected duplications, including line numbers and similarity percentages.
- Logging: Utilizes `spdlog` for robust logging capabilities.

## Usage
Run noditto from the command line, specifying the file to check for duplications:
```sh
./noditto /path/to/your/file.cpp
```
Command-Line Options

- -h, --help: Display help information.
- -o, --output: Specify the output file for the duplication report.

## How It Works

1. Parsing Source Code:
    - Noditto parses the source code file and generates its AST.
    - The AST represents the structure of the source code.

2. Extracting Subtrees:
    - Noditto traverses the AST to extract all possible subtrees.

3. Hashing Subtrees:
    - Each subtree is hashed to enable quick comparison.

4. Comparing Hashes:
    - Noditto stores the hashes in a data structure and compares them to find duplicate subtrees.

5. Generating Reports:
    - Ditto generates a detailed report of the detected duplications, including file names, line numbers, and similarity percentages.
    
## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue if you find any bugs or have suggestions for improvements.

## License 
MIT
