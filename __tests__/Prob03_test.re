open Jest;
open Prob03;

describe("Prob03.kth", () => {
  open Expect;
  test("handles the case of list cantaining enough elements", () =>
    expect((
      kth([1, 2, 3], 1),
      kth([1, 2, 3], 2),
      kth([1, 2, 3], 3),
      kth(["jack", "jone", "mary", "vincent", "Tom"], 1),
      kth(["jack", "jone", "mary", "vincent", "Tom"], 2),
      kth(["jack", "jone", "mary", "vincent", "Tom"], 3),
      kth(["jack", "jone", "mary", "vincent", "Tom"], 4),
      kth(["jack", "jone", "mary", "vincent", "Tom"], 5),
    ))
    |> toEqual((1, 2, 3, "jack", "jone", "mary", "vincent", "Tom"))
  );

  testAll(
    "throws expection when the list doesn't have enough elements or passing invalid index",
    [
      expect(() =>
        kth([1, 2, 3], 0)
      ),
      expect(() =>
        kth([1, 2, 3], 4)
      ),
      expect(() =>
        kth([1, 2, 3], -1)
      ),
      expect(() =>
        kth([1, 2, 3], -99)
      ),
      expect(() =>
        kth([1, 2, 3], 1000001)
      ),
    ],
    toThrow,
  );
});

describe("Prob03.kth2", () => {
  open Expect;
  test("handles the case of list cantaining enough elements", () =>
    expect((
      kth2([1, 2, 3], 1),
      kth2([1, 2, 3], 2),
      kth2([1, 2, 3], 3),
      kth2(["jack", "jone", "mary", "vincent", "Tom"], 1),
      kth2(["jack", "jone", "mary", "vincent", "Tom"], 2),
      kth2(["jack", "jone", "mary", "vincent", "Tom"], 3),
      kth2(["jack", "jone", "mary", "vincent", "Tom"], 4),
      kth2(["jack", "jone", "mary", "vincent", "Tom"], 5),
    ))
    |> toEqual((1, 2, 3, "jack", "jone", "mary", "vincent", "Tom"))
  );

  testAll(
    "throws expection when the list doesn't have enough elements or passing invalid index",
    [
      expect(() =>
        kth2([1, 2, 3], 0)
      ),
      expect(() =>
        kth2([1, 2, 3], 4)
      ),
      expect(() =>
        kth2([1, 2, 3], -1)
      ),
      expect(() =>
        kth2([1, 2, 3], -99)
      ),
      expect(() =>
        kth2([1, 2, 3], 1000001)
      ),
    ],
    toThrow,
  );
});