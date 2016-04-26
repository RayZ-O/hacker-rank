(defn read-lines [n]
  (repeatedly n (fn [] (->> (clojure.string/split (read-line) #"\s+")
                            (map #(Double. %))))))

(let [N (Integer. (read-line))
      coors (cycle (read-lines N))
      shoelace (fn [[x1 y1] [x2 y2]]
                 (- (* x1 y2) (* x2 y1)))
      shoelaces (map #(shoelace %1 %2) coors (rest coors))
      area (* 0.5 (Math/abs (reduce + (take N shoelaces))))]
  (println area))
