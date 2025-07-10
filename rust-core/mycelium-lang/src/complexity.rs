pub fn shannon_entropy(sequence: &str) -> f64 {
    let mut freq = std::collections::HashMap::new();
    let len = sequence.len() as f64;

    for c in sequence.chars() {
        *freq.entry(c).or_insert(0) += 1;
    }

    freq.values()
        .map(|&count| {
            let p = count as f64 / len;
            -p * p.log2()
        })
        .sum()
}

pub fn lz_complexity(sequence: &str) -> usize {
    let mut dict = std::collections::HashSet::new();
    let mut w = String::new();
    let mut c = 0;

    for ch in sequence.chars() {
        w.push(ch);
        if !dict.contains(&w) {
            dict.insert(w.clone());
            w.clear();
            c += 1;
        }
    }

    c
}
