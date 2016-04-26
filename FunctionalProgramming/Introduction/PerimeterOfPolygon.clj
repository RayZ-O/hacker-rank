(defn read-lines [n]
  (repeatedly n (fn [] (->> (clojure.string/split (read-line) #"\s+")
                            (map #(Double. %))))))

(let [N (Integer. (read-line))
      coors (cycle (read-lines N))
      pow2 (fn [x] (* x x))
      distance (fn [[x1 y1] [x2 y2]]
                 (Math/sqrt (+ (pow2 (- x1 x2))
                               (pow2 (- y1 y2)))))
      distances (map #(distance %1 %2) coors (rest coors))
      perimeter (reduce + (take N distances))]
  (println perimeter))

