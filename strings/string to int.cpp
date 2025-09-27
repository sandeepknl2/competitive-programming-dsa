   int n = s.size();
    int i = 0;

    // 1. Skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // 2. Check for sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Parse digits
    long long num = 0; // use long long to handle overflow
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');

        // 4. Handle overflow
        if (sign * num > INT_MAX) return INT_MAX;
        if (sign * num < INT_MIN) return INT_MIN;

        i++;
    }

    return sign * num;
}

 int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++; // skip leading spaces

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    long long num = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');

        if (sign * num > INT_MAX) return INT_MAX;
        if (sign * num < INT_MIN) return INT_MIN;

        i++;
    }

    return sign * num;