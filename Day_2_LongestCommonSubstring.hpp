#include<string>
std::string LongestCommonString(std::string a, std::string b)
{
    auto aLength = a.size();
    auto bLength = b.size();
    uint32_t LongestCommonSuff[aLength + 1][bLength + 1];
    uint32_t commonSubstringLength = 0;
    uint32_t beginIndex = 0;

    for (int i = 0; i <= aLength; i++)
    {
        for (int j = 0; j <= bLength; j++)
        {
            if (i == 0 || j == 0)
            {
                LongestCommonSuff[i][j] = 0;
            }
            else
            {
                if (a[i - 1] == b[j - 1])
                {
                    LongestCommonSuff[i][j] = LongestCommonSuff[i - 1][j - 1] + 1;
                    if(commonSubstringLength < LongestCommonSuff[i][j])
                    {
                        commonSubstringLength = LongestCommonSuff[i][j];
                        beginIndex = i - commonSubstringLength;
                    }
                }
                else
                {
                    LongestCommonSuff[i][j] = 0;
                }
            }
        }
    }
    return a.substr(beginIndex, commonSubstringLength);
}