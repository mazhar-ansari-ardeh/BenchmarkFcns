% This function creates an offspring from a given parent, within a given
% boundary. This function is used by the ARO method. 
function bud = aro_reproduce(parent, lb, ub)
    len = length(parent);
    bud = zeros(1, len);
    for i = 1:len
        parent_component = aro_dec2arobin(parent(i));
        % In the original paper by Farasat, et al., the length of a
        % choromosome is named L. 
        L = length(parent_component); 
        
        % In the original paper by Farasat, et al., the g is used to
        % indicate the number of bits that are selected from a chromosome
        % to produce a Larva. Accordingly, g_begin and g_end are the
        % begining and ending index of such selection from the chromosome.
        g_end = randi(L);
        if(parent_component(g_end) == ')')
            g_end = g_end - 1;
        end
        if(parent_component(g_end) == ',')
            g_end = g_end + 1;
        end
        if(parent_component(g_end) == '(')
            g_end = g_end + 1;
        end
        g_begin = randi(g_end - 1); 
        if(parent_component(g_begin) == ',')
            g_begin = g_begin +1;
        end
        if(parent_component(g_begin) == '(')
            g_begin = g_begin + 1;
        end
        for j = g_begin:g_end
            larva_component = parent_component;
            p = 1 / (1 + log(g_end - g_begin));
            if(rand <= p)
                continue;
            end
            if larva_component(j) == '0'
                larva_component(j) = '1';
            else
                if larva_component(j) == '1'
                    larva_component(j) = '0';
                end
            end
        end
%         fprintf('parent:\t%s\nlarva:\t%s\t%f\t%f\n\n', parent_component, larva_component, aro_arobin2dec(parent_component), aro_arobin2dec(larva_component));
        drawnow update
        bud(i) = aro_arobin2dec(larva_component);
    end
    
    % Check bounds of the problem space. 
    ind = find(ub - bud < 0);
    bud(ind) = ub(ind);
    ind = find(bud - lb <0);
    bud(ind) = lb(ind);
end

function [aro_bin] = aro_dec2arobin(x)
    if x >= 0
        sign = '0';
    else
        sign = '1';
    end
    x = abs(x);
    splittedNumber = regexp(num2str(x),'\.','split');
    BeforeComma = str2double(splittedNumber{1});
    if(length(splittedNumber) > 1)
        AfterComma = str2double(splittedNumber{2});
    else
        AfterComma = 0;
    end
    
    aro_bin = ['(', sign, ',', dec2bin(BeforeComma), ',' dec2bin(AfterComma), ')'];
end

function retval = aro_arobin2dec(aro_bin)

    aro_bin = aro_bin(2:end - 1);
    splitted_bin = regexp(aro_bin, ',', 'split');
    
    BeforeComma = splitted_bin{2};
    AfterComma = splitted_bin{3};
    
    BeforeComma = num2str(bin2dec(BeforeComma));
    AfterComma = num2str(bin2dec(AfterComma));
    
    retval = str2double([BeforeComma, '.', AfterComma]);
    if(splitted_bin{1} == '1')
        retval = -retval;
    end
end