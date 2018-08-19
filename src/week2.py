string = "GAGG"
DNA = "TTTAGAGCCTTCAGAGG"
num = 2


def hamming_distance(s1, s2):
    assert len(s1) == len(s2)
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))


def ApproximatePatternMatching(Text, Pattern, d):
    l = len(Text)
    k = len(Pattern)
    substrings = [Text[i:i+k] for i in range(l-k+1)]
    return [i for i, sub in enumerate(substrings) if hamming_distance(Pattern, sub) <= d]


def ApproximatePatternCount(Text, Pattern, d):
    return len(ApproximatePatternMatching(Text, Pattern, d))


def Neighbors(Sequence):
    alphabet = "ACGT"
    my_neighbors = [Sequence]
    for i in range(len(Sequence)):
        l = Sequence[i]
        for j in range(len(alphabet)):
            if (alphabet[j] != l):
                my_neighbors.append(Sequence[0:i] + alphabet[j] + Sequence[i+1:])
    return my_neighbors

