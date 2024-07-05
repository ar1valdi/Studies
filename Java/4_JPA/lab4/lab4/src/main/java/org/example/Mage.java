package org.example;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;

@Entity
public class Mage {
        @Id
        private String name;
        private int level;
        @ManyToOne
        private Tower tower;

        public String getName() {
                return name;
        }

        public void setName(String name) {
                this.name = name;
        }

        public int getLevel() {
                return level;
        }

        public void setLevel(int level) {
                this.level = level;
        }

        public Tower getTower() {
                return tower;
        }

        public void setTower(Tower tower) {
                this.tower = tower;
        }

        Mage(String name, int level) {
                this.name = name;
                this.level = level;
        }

        @Override
        public String toString() {
                if (this.tower != null) {
                        return name + "{" + level + "," + tower.getName() + "}";
                }
                return name + "{" + level + "}";
        }
}
