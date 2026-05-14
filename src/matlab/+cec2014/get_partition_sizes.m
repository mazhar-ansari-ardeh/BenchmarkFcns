function sizes = get_partition_sizes(fid, n)
    % GET_PARTITION_SIZES Helper for CEC 2014 Hybrid function partitions.

    switch fid
        case {17, 18}, p = [0.3, 0.3, 0.4];
        case {19, 20}, p = [0.2, 0.2, 0.3, 0.3];
        case {21, 22}, p = [0.1, 0.2, 0.2, 0.2, 0.3];
        otherwise
            sizes = n;
            return;
    end

    sizes = zeros(1, length(p));
    current_sum = 0;
    for i = 1:length(p)-1
        sz = ceil(p(i) * n);
        sizes(i) = sz;
        current_sum = current_sum + sz;
    end
    sizes(end) = n - current_sum;
end
