# MMO RPG by ULTRA M2 (Stepan Belogura)

## Используемые паттерны

### Абстрактная фабрика

Проект использует порождающий паттерн Abstract Factory, так как классы объектов, создаваемых фабриками можно распределить по семействам:

| Семейство | Классы |
| - | - |
| `KingdomGuardianFactory` | `Paladin`, `CrossbowMan`, `Cleric` |
| `ForestKeeperFactory` | `Ent`, `Centaur`, `Druid` |
| `UndeadFactory` | `Skeleton`, `ShadowArcher`, `Necromancer` |

Основная фабрика `UnitFactory`, представляющая из себя интерфейс с чисто виртуальными методами, содержит 3 метода `create_knight()`, `create_archer()`, `create_mage()`. Классы `KingdomGuardianFactory`, `ForestKeeperFactory` и `UndeadFactory` наследуют данные методы и создают юнитов типа методов, но семейства класса-наследника.