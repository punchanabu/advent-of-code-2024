use std::collections::HashSet;
use std::fs::read_to_string;

#[derive(Debug)]
enum Direction {
    Up,
    Right,
    Down,
    Left,
}

impl Direction {
    fn turn_right(&self) -> Direction {
        match self {
            Direction::Up => Direction::Right,
            Direction::Right => Direction::Down,
            Direction::Down => Direction::Left,
            Direction::Left => Direction::Up,
        }
    }

    fn get_delta(&self) -> (i32, i32) {
        match self {
            Direction::Up => (-1, 0),
            Direction::Right => (0, 1),
            Direction::Down => (1, 0),
            Direction::Left => (0, -1),
        }
    }
}

fn parse_input(input: &str) -> (Vec<Vec<char>>, (usize, usize, Direction)) {
    let grid: Vec<Vec<char>> = input.lines()
        .map(|line| line.chars().collect())
        .collect();
    
    let mut start = None;
    for (i, row) in grid.iter().enumerate() {
        for (j, &cell) in row.iter().enumerate() {
            if cell == '^' {
                start = Some((i, j, Direction::Up));
            }
        }
    }
    
    (grid, start.unwrap())
}

fn is_valid_position(pos: (i32, i32), grid: &Vec<Vec<char>>) -> bool {
    pos.0 >= 0 && 
    pos.1 >= 0 && 
    pos.0 < grid.len() as i32 && 
    pos.1 < grid[0].len() as i32
}

fn solve(input: &str) -> usize {
    let (grid, (start_row, start_col, start_dir)) = parse_input(input);
    let mut visited = HashSet::new();
    let mut current_pos = (start_row as i32, start_col as i32);
    let mut current_dir = start_dir;
    
    visited.insert((current_pos.0 as i32, current_pos.1 as i32));
    
    loop {
        let (dy, dx) = current_dir.get_delta();
        let next_pos = (current_pos.0 + dy, current_pos.1 + dx);
        
        if !is_valid_position(next_pos, &grid) {
            break;
        }
        
        if grid[next_pos.0 as usize][next_pos.1 as usize] == '#' {
            current_dir = current_dir.turn_right();
        } else {
            current_pos = next_pos;
            visited.insert((current_pos.0, current_pos.1));
        }
    }
    
    visited.len()
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let input = read_to_string("in.txt")?;
    let result = solve(&input);
    println!("{}", result);
    Ok(())
}