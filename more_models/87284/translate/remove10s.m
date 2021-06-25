% remove10s.m
% this script removes type 10 from the cell morph in c

% find out how many type 10s there are

type10s=0;

for i=1:length(c)
  if (c(i,2)==10)
    type10s = type10s + 1;
% disp(['removing number ' int2str(type10s)]);

  end
end

removeme=zeros(1,type10s);

removeindex=1;
for i=1:length(c)
  if (c(i,2)==10)
    removeme(removeindex)=i;
removeindex = removeindex+1;
% disp(['removing number ' int2str(type10s)]);

  end
end

current_matrix=c;
for i=type10s:-1:1
  disp(['deleteing row ' int2str(removeme(i))])
  new_matrix=delrow(removeme(i), current_matrix);
current_matrix = new_matrix;
end
