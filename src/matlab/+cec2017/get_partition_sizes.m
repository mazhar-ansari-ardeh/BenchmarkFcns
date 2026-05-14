function sizes = get_partition_sizes(fid, n)
    switch fid
        case {11, 12, 13}
            p = [0.2, 0.4, 0.4];
        case {14, 15, 16}
            p = [0.2, 0.2, 0.3, 0.3];
        case 17
            p = [0.1, 0.2, 0.2, 0.2, 0.3];
        case {18, 19}
            p = [0.2, 0.2, 0.2, 0.2, 0.2];
        case 20
            p = [0.1, 0.1, 0.2, 0.2, 0.2, 0.2];
        otherwise
            sizes = n;
            return;
    end

    sizes = zeros(1, length(p));
    sum_s = 0;
    for i = 1:length(p)-1
        s = ceil(p(i) * n);
        sizes(i) = s;
        sum_s = sum_s + s;
    end
    sizes(end) = n - sum_s;
end
