# Heartbleed Demo

Demonstrate the basic C concepts behind the "Heartbleed" bug.


## To build

`make`

## To run

`./heartbeat`

## Output

`./heartbeat > output.txt`
`strings output.txt`

## Output

```text
Heartbeat was valid! expected 'Heartbeat Check: Monkey' and found 'Heartbeat
Check: Monkey'

Heartbeat was invalid: expected 'hack' but found 'Heartbeat Check: Dog
Update Password: s33krit
Dupe
Update Password: superSwordfish222
Heartbeat Check: Monkey
```
