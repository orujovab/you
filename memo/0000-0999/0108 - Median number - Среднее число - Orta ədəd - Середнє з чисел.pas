var a, b, c:integer;
begin
  readln (a, b, c);
  if (b<a) and (a<c) then begin writeln (a); halt; end;
  if (c<a) and (a<b) then begin writeln (a); halt; end;
  if (a<b) and (b<c) then begin writeln (b); halt; end;
  if (c<b) and (b<a) then begin writeln (b); halt; end;
  if (a<c) and (c<b) then begin writeln (c); halt; end;
  if (b<c) and (c<a) then begin writeln (c); halt; end;
end.
