use std::collections::HashMap;

pub type State = String;
pub type TransitionGraph = HashMap<State, Vec<State>>;

pub fn build_state_graph(words: &[Vec<usize>]) -> TransitionGraph {
    let mut graph: TransitionGraph = HashMap::new();

    for window in words.windows(2) {
        let from = format!("{:?}", window[0]);
        let to = format!("{:?}", window[1]);

        graph.entry(from).or_insert_with(Vec::new).push(to);
    }

    graph
}
