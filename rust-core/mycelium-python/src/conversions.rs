// Example conversion helpers (empty for now)

pub fn normalize_float_vec(vec: &[f32]) -> Vec<f32> {
    let min = vec.iter().cloned().fold(f32::INFINITY, f32::min);
    let max = vec.iter().cloned().fold(f32::NEG_INFINITY, f32::max);

    if (max - min).abs() < f32::EPSILON {
        return vec.to_vec();
    }

    vec.iter().map(|&x| (x - min) / (max - min)).collect()
}
