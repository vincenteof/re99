/*  Flatten a nested list structure */

type node('a) =
  | One('a)
  | Many(list(node('a)));

let rec flattenNodes =
  fun
  | [] => []
  | [One(elem), ...rest] => [elem, ...flattenNodes(rest)]
  | [Many(lst), ...rest] =>
    List.([lst, rest] |> map(flattenNodes) |> concat);