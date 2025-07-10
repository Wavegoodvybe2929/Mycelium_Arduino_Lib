def extract_words(spike_indices, theta=100):
    words = []
    current_word = []

    for i in range(len(spike_indices) - 1):
        current_word.append(spike_indices[i])
        if spike_indices[i + 1] - spike_indices[i] > theta:
            words.append(current_word.copy())
            current_word.clear()

    # Add last word
    current_word.append(spike_indices[-1])
    words.append(current_word)

    return words

def analyze_syntax(words):
    transitions = {}
    for i in range(len(words) - 1):
        from_state = str(words[i])
        to_state = str(words[i + 1])
        if from_state not in transitions:
            transitions[from_state] = []
        transitions[from_state].append(to_state)

    return transitions
