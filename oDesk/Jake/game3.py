#!/usr/bin/python

import sys

corps = [];

contr = 0;

def get_max(corp):
    val = 1;
    for (k, v) in corp.items():
        val = max(val, v);
    return val;

try:
    line = sys.stdin.readline()
except KeyboardInterrupt:
    exit(1);

(N, M, L) = line.split();

while 1:
# read each line from input
    try:
        line = sys.stdin.readline()
    except KeyboardInterrupt:
        break

    if not line:
        break

    gc = line.split();

# if two player, it's a game
    if len(gc) == 2:
# if both player in corporation, do nothing, skip
        skip = False;
        wins = None;
        loss = None;
        for c in corps:
            if gc[0] in c:
                wins = c;
            if gc[1] in c:
                loss = c;

            if gc[0] in c and gc[1] in c:
                skip = True;
                break;

        if skip:
            continue;

        if wins is None and loss is None:
            c = {};
            c[gc[0]] = 2;
            c[gc[1]] = 1;
            corps.append(c);
            continue;

        if wins is None and loss is not None:
            val = get_max(loss);
            loss[gc[0]] = 1 + val;

        if wins is not None and loss is None:
            for (k, v) in wins.items():
                wins[k] = v + 1;
            wins[gc[1]] = 1;

        if wins is not None and loss is not None:
            val = get_max(loss);
            for (k, v) in wins.items():
                wins[k] = v + val;
            wins[gc[1]] = loss[gc[1]];
            del loss[gc[1]];

# the player will donate the points
    if len(gc) == 1:
        found = False;
        for c in corps:
            if gc[0] in c:
                contr = contr + c[gc[0]];
                found = True;
                break;
        if not found:
            contr = contr + 1;

print contr



