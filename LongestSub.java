class LongestSub {
    public static void main(String[] args) {
        String str = "geeksforgeeks";
        int i = 0; 
        int j = 0; 
        int maxLength = 0;
        String longestStr = "";
        while (j < str.length()) {
            char currChar = str.charAt(j);
            for (int k = i; k < j; k++) {
                if (str.charAt(k) == currChar) {
                    i = k + 1;
                    break;
                }
            }
            if ((j - i + 1) > maxLength) {
                maxLength = j - i + 1;
                longestStr = str.substring(i, j + 1);
            }
            j++; 
        }
        System.out.println("Input String: " + str);
        System.out.println("Longest Substring: " + longestStr);
        System.out.println("Length: " + maxLength);
    }
}