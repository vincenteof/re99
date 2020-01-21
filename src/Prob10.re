let lenEncode = lst => {
  Prob09.(
    List.(lst |> pack |> map(subList => (length(subList), hd(subList))))
  );
};