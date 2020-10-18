#include <iostream>

// A function that returns the displacement given by the command at index of the string s
std::pair<int, int> process_command(std::string s, int &index)
{
    // No commands to process if we have finished the command string
    if (index >= s.size())
    {
        return {0, 0};
    }

    // Otherwise process current command
    std::pair<long long, long long> displacement = {0, 0};
    size_t digits;
    int times;
    try
    {
        // Try to extract a number
        times = stoi(s.substr(index), &digits);
        // If we were able to extract a number, it means we have a repeating command
        // So ignore the front bracket '(' and process the command within
        index += digits + 1;
        displacement = process_command(s, index);
        // Multiply by the repetition index
        displacement.first *= times;
        displacement.second *= times;
        // Ignore the closing bracket ')'
        index++;
    }
    catch (std::invalid_argument)
    {
        // If number extraction was not successful, the symbol must be any of these
        switch (s[index])
        {
        case 'N':
            displacement = {0, -1};
            break;
        case 'S':
            displacement = {0, 1};
            break;
        case 'E':
            displacement = {1, 0};
            break;
        case 'W':
            displacement = {-1, 0};
            break;
        case ')':
            return {0, 0};
        }
        // And we move to the next symbol
        index++;
    }
    // Get the next command in the sequence
    std::pair<int, int> following = process_command(s, index);

    // Apply the modulus to simulate the torus
    displacement.first += following.first + 1e9;
    displacement.second += following.second + 1e9;
    displacement.first %= int(1e9);
    displacement.second %= int(1e9);

    return displacement;
}

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::string directions;

        std::cin >> directions;
        int start = 0; // Starting index

        // Process the whole command
        std::pair<int, int> displacement = process_command(directions, start);

        // Add start from (1,1)
        displacement.first += 1;
        displacement.second += 1;

        std::cout << "Case #" << i + 1 << ": " << displacement.first << " " << displacement.second << "\n";
    }
    return 0;
}
