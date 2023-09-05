    for (int p = 1; p <= 5; p++)
    {
        outputFile << "Power " << p << ":" << endl;
        // initialize output matrix to all zeros
        int Mp[MAX_SIZE][MAX_SIZE] = {0};
        // compute power of matrix
        matrixPower(M, n, p, Mp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // write matrix element to output file
                outputFile << Mp[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile << endl;
    }