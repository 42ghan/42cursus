arr = Array.new(ARGV[0].to_i) { rand(-2147483648..2147483647) }

puts arr.uniq