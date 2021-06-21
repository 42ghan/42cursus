
# SECTION Arguments setting
x_len = rand(3..30)
y_len = rand(3..30)

if x_len == 3 && y_len < 5
  y_len = rand(5..30)
elsif y_len == 3 && x_len < 5
  x_len = rand(5..30)
end

# SECTION Map generation function
def mapgen(x, y)
  map = []
  mid = Array.new(x, '0')
  mid[0] = '1'
  mid[-1] = '1'
  map.append(Array.new(x, '1'))
  (1..(y - 1)).to_a.each { |i| map.append(mid.clone) }
  map.append(Array.new(x, '1'))
  empty = (x - 2) * (y - 2)

  # NOTE Filling appropriate amount of 'C' and '1'
  rand(1..(empty / 4)).times { map[rand(1..(y - 2))][rand(1..(x - 2))] = 'C' }
  rand(1..(empty / 4)).times {
    x_idx = rand(1..(x - 2))
    y_idx = rand(1..(y - 2))
    map[y_idx][x_idx] = '1' if map[y_idx][x_idx] != 'C'
  }

  # NOTE Fill 'E' and 'P'
  empty.times {
    x_idx = rand(1..(x - 2))
    y_idx = rand(1..(y - 2))
    if map[y_idx][x_idx] == '0' or map[y_idx][x_idx] == '1'
      map[y_idx][x_idx] = 'P'
      break
    end
  }
  empty.times {
    x_idx = rand(1..(x - 2))
    y_idx = rand(1..(y - 2))
    if map[y_idx][x_idx] == '0' or map[y_idx][x_idx] == '1'
      map[y_idx][x_idx] = 'E'
      break
    end
  }

  #NOTE Write .ber file
  map.each_index { |i|
    if i == 0
      File.write('map.ber', "#{map[i].join}", mode: 'w')
    else
      File.write('map.ber', "#{map[i].join}", mode: 'a')
    end
    File.write('map.ber', "\n", mode: 'a') unless i == y
  }
end

mapgen(x_len, y_len)
