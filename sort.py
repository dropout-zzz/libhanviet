#!/usr/bin/env python3
import traceback
import sys

all_keys: list[str] = []
entries: dict[str, list[str]] = {}

with open('dict.txt', 'r') as f:
  for n, line in enumerate(f, start=1):
    if line == '\n' or line.startswith('#'):
      continue

    try:
      key, value, _ = line.removesuffix('\n').split(':', 2)
      if key == '':
        raise ValueError('key cannot be empty')
    except ValueError:
      traceback.print_exc()
      print(f'{sys.argv[0]}: line #{n} is invalid.')
      sys.exit(1)

    if key not in all_keys:
      all_keys.append(key)

    if key not in entries:
      entries[key] = []

    if value in entries[key]:
      continue

    entries[key].append(value)

all_keys.sort()

with open('dict.txt', 'w') as f:
  f.write('# sort using libhanviet/sort.py\n')
  f.write('\n')

  for key in all_keys:
    for value in entries[key]:
      f.write(f'{key}:{value}:\n')
