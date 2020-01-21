open Jest;
open Prob07;

describe("Prob07.flattenNodes", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(flattenNodes([])) |> toEqual([])
  );
  test("handles the case of list with `One` elements", () =>
    expect((
      flattenNodes([One(1)]),
      flattenNodes([One(1), One(2), One(1)]),
      flattenNodes([One(1), One(1)]),
      flattenNodes([One(1), One(2), One(3), One(4)]),
      flattenNodes([One("a"), One("b"), One("c"), One("d"), One("e")]),
    ))
    |> toEqual((
         [1],
         [1, 2, 1],
         [1, 1],
         [1, 2, 3, 4],
         ["a", "b", "c", "d", "e"],
       ))
  );

  test("handles the case of list with `Manty` elements", () =>
    expect((
      flattenNodes([Many([One(1)])]),
      flattenNodes([Many([One(1)]), Many([One(2)]), Many([One(3)])]),
      flattenNodes([Many([One(1), One(2)]), Many([One(3), One(5)])]),
      flattenNodes([
        Many([One(1), One(2)]),
        Many([One(3)]),
        Many([One(4), One(5), One(6)]),
        Many([One(7), One(8)]),
        Many([One(9)]),
      ]),
      flattenNodes([
        Many([One("i"), One("have")]),
        Many([One("something")]),
        Many([One("very"), One("good"), One("and")]),
        Many([One("exciting"), One("to")]),
        Many([One("tell"), One("you")]),
      ]),
    ))
    |> toEqual((
         [1],
         [1, 2, 3],
         [1, 2, 3, 5],
         [1, 2, 3, 4, 5, 6, 7, 8, 9],
         [
           "i",
           "have",
           "something",
           "very",
           "good",
           "and",
           "exciting",
           "to",
           "tell",
           "you",
         ],
       ))
  );

  test("handles the case of list with mixed elements", () =>
    expect((
      flattenNodes([Many([One(1)]), One(2)]),
      flattenNodes([
        One(0),
        Many([One(1)]),
        Many([One(2)]),
        Many([One(3), One(4)]),
        One(5),
      ]),
      flattenNodes([
        Many([
          One(1),
          One(2),
          Many([One(1), Many([One(2), One(3)]), One(4)]),
        ]),
        One(3),
        One(4),
        Many([
          Many([
            Many([One(1), Many([One(2)])]),
            One(3),
            Many([One(4)]),
          ]),
          One(5),
          Many([One(6)]),
        ]),
      ]),
    ))
    |> toEqual((
         [1, 2],
         [0, 1, 2, 3, 4, 5],
         [1, 2, 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 5, 6],
       ))
  );
});