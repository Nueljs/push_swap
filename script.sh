for i in $(seq 1 20); do
    ARG=$(python3 -c "import random; l=list(range(1,501)); random.shuffle(l); print(*l)")
    resultado=$(./push_swap $ARG | wc -l)
    echo "Test $i: $resultado"
    if [ $resultado -gt 5500 ]; then
        echo "^^^ CASO PROBLEMÁTICO: $ARG"
    fi
done