#!/bin/bash

in_list=(test_samples_encode/in-*.txt)

echo "---ENCODING---"
for i in "${!in_list[@]}"; do
  echo "Encode test №$((i + 1))"
  ./coder "-e" "${in_list[$i]}" "test_samples_encode/out-$((i + 1)).txt"
  if cmp -s "test_samples_encode/out-expected-$((i + 1)).txt" "test_samples_encode/out-$((i + 1)).txt"; then
    echo "Passed"
  else
    echo "Fail"
    break
  fi
done

echo "---DECODING---"

in_list=(test_samples_decode/in-*.txt)

for i in "${!in_list[@]}"; do
  echo "Decode test №$((i + 1))"
  ./coder "-d" "${in_list[$i]}" "test_samples_decode/out-$((i + 1)).txt"
  if cmp -s "test_samples_decode/out-expected-$((i + 1)).txt" "test_samples_decode/out-$((i + 1)).txt"; then
    echo "Passed"
  else
    echo "Fail"
    break
  fi
done