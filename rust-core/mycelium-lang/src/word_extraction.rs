pub fn extract_words(spike_indices: &[usize], theta: usize) -> Vec<Vec<usize>> {
    let mut words = Vec::new();
    let mut current_word = Vec::new();

    for window in spike_indices.windows(2) {
        current_word.push(window[0]);
        if window[1] - window[0] > theta {
            words.push(current_word.clone());
            current_word.clear();
        }
    }

    // Push last word if any
    if let Some(&last) = spike_indices.last() {
        current_word.push(last);
        words.push(current_word);
    }

    words
}
