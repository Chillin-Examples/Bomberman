#ifndef _KS_MODELS_H_
#define _KS_MODELS_H_

#include <string>
#include <vector>
#include <map>
#include <array>


namespace ks
{

#ifndef _KS_OBJECT_
#define _KS_OBJECT_

class KSObject
{
public:
	static inline const std::string nameStatic() { return ""; }
	virtual inline const std::string name() const = 0;
	virtual std::string serialize() const = 0;
	virtual unsigned int deserialize(const std::string &, unsigned int = 0) = 0;
};

#endif // _KS_OBJECT_


namespace models
{

enum class ECellType
{
	Empty = 0,
	DestroyableBlock = 1,
	UndestroyableBlock = 2,
};


class Cell : public KSObject
{

protected:

	ECellType __type;

	bool __has_type;


public: // getters

	inline ECellType type() const
	{
		return __type;
	}
	

public: // reference getters

	inline ECellType &ref_type() const
	{
		return (ECellType&) __type;
	}
	

public: // setters

	inline void type(const ECellType &type)
	{
		__type = type;
		has_type(true);
	}
	

public: // has_attribute getters

	inline bool has_type() const
	{
		return __has_type;
	}
	

public: // has_attribute setters

	inline void has_type(const bool &has_type)
	{
		__has_type = has_type;
	}
	

public:

	Cell()
	{
		has_type(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Cell";
	}
	
	virtual inline const std::string name() const
	{
		return "Cell";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize type
		s += __has_type;
		if (__has_type)
		{
			unsigned char tmp1 = (unsigned char) __type;
			auto tmp2 = reinterpret_cast<char*>(&tmp1);
			s += std::string(tmp2, sizeof(unsigned char));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize type
		__has_type = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_type)
		{
			unsigned char tmp3;
			tmp3 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			__type = (ECellType) tmp3;
		}
		
		return offset;
	}
};


class Bomberman : public KSObject
{

protected:

	unsigned char __x;
	unsigned char __y;
	unsigned char __bomb_level;
	bool __is_dead;

	bool __has_x;
	bool __has_y;
	bool __has_bomb_level;
	bool __has_is_dead;


public: // getters

	inline unsigned char x() const
	{
		return __x;
	}
	
	inline unsigned char y() const
	{
		return __y;
	}
	
	inline unsigned char bomb_level() const
	{
		return __bomb_level;
	}
	
	inline bool is_dead() const
	{
		return __is_dead;
	}
	

public: // reference getters

	inline unsigned char &ref_x() const
	{
		return (unsigned char&) __x;
	}
	
	inline unsigned char &ref_y() const
	{
		return (unsigned char&) __y;
	}
	
	inline unsigned char &ref_bomb_level() const
	{
		return (unsigned char&) __bomb_level;
	}
	
	inline bool &ref_is_dead() const
	{
		return (bool&) __is_dead;
	}
	

public: // setters

	inline void x(const unsigned char &x)
	{
		__x = x;
		has_x(true);
	}
	
	inline void y(const unsigned char &y)
	{
		__y = y;
		has_y(true);
	}
	
	inline void bomb_level(const unsigned char &bomb_level)
	{
		__bomb_level = bomb_level;
		has_bomb_level(true);
	}
	
	inline void is_dead(const bool &is_dead)
	{
		__is_dead = is_dead;
		has_is_dead(true);
	}
	

public: // has_attribute getters

	inline bool has_x() const
	{
		return __has_x;
	}
	
	inline bool has_y() const
	{
		return __has_y;
	}
	
	inline bool has_bomb_level() const
	{
		return __has_bomb_level;
	}
	
	inline bool has_is_dead() const
	{
		return __has_is_dead;
	}
	

public: // has_attribute setters

	inline void has_x(const bool &has_x)
	{
		__has_x = has_x;
	}
	
	inline void has_y(const bool &has_y)
	{
		__has_y = has_y;
	}
	
	inline void has_bomb_level(const bool &has_bomb_level)
	{
		__has_bomb_level = has_bomb_level;
	}
	
	inline void has_is_dead(const bool &has_is_dead)
	{
		__has_is_dead = has_is_dead;
	}
	

public:

	Bomberman()
	{
		has_x(false);
		has_y(false);
		has_bomb_level(false);
		has_is_dead(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Bomberman";
	}
	
	virtual inline const std::string name() const
	{
		return "Bomberman";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize x
		s += __has_x;
		if (__has_x)
		{
			unsigned char tmp5 = __x;
			auto tmp6 = reinterpret_cast<char*>(&tmp5);
			s += std::string(tmp6, sizeof(unsigned char));
		}
		
		// serialize y
		s += __has_y;
		if (__has_y)
		{
			unsigned char tmp8 = __y;
			auto tmp9 = reinterpret_cast<char*>(&tmp8);
			s += std::string(tmp9, sizeof(unsigned char));
		}
		
		// serialize bomb_level
		s += __has_bomb_level;
		if (__has_bomb_level)
		{
			unsigned char tmp11 = __bomb_level;
			auto tmp12 = reinterpret_cast<char*>(&tmp11);
			s += std::string(tmp12, sizeof(unsigned char));
		}
		
		// serialize is_dead
		s += __has_is_dead;
		if (__has_is_dead)
		{
			bool tmp14 = __is_dead;
			auto tmp15 = reinterpret_cast<char*>(&tmp14);
			s += std::string(tmp15, sizeof(bool));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize x
		__has_x = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_x)
		{
			__x = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize y
		__has_y = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_y)
		{
			__y = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize bomb_level
		__has_bomb_level = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_bomb_level)
		{
			__bomb_level = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize is_dead
		__has_is_dead = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_is_dead)
		{
			__is_dead = *((bool*) (&s[offset]));
			offset += sizeof(bool);
		}
		
		return offset;
	}
};


class Bomb : public KSObject
{

protected:

	unsigned char __x;
	unsigned char __y;
	unsigned char __timer;
	unsigned char __level;

	bool __has_x;
	bool __has_y;
	bool __has_timer;
	bool __has_level;


public: // getters

	inline unsigned char x() const
	{
		return __x;
	}
	
	inline unsigned char y() const
	{
		return __y;
	}
	
	inline unsigned char timer() const
	{
		return __timer;
	}
	
	inline unsigned char level() const
	{
		return __level;
	}
	

public: // reference getters

	inline unsigned char &ref_x() const
	{
		return (unsigned char&) __x;
	}
	
	inline unsigned char &ref_y() const
	{
		return (unsigned char&) __y;
	}
	
	inline unsigned char &ref_timer() const
	{
		return (unsigned char&) __timer;
	}
	
	inline unsigned char &ref_level() const
	{
		return (unsigned char&) __level;
	}
	

public: // setters

	inline void x(const unsigned char &x)
	{
		__x = x;
		has_x(true);
	}
	
	inline void y(const unsigned char &y)
	{
		__y = y;
		has_y(true);
	}
	
	inline void timer(const unsigned char &timer)
	{
		__timer = timer;
		has_timer(true);
	}
	
	inline void level(const unsigned char &level)
	{
		__level = level;
		has_level(true);
	}
	

public: // has_attribute getters

	inline bool has_x() const
	{
		return __has_x;
	}
	
	inline bool has_y() const
	{
		return __has_y;
	}
	
	inline bool has_timer() const
	{
		return __has_timer;
	}
	
	inline bool has_level() const
	{
		return __has_level;
	}
	

public: // has_attribute setters

	inline void has_x(const bool &has_x)
	{
		__has_x = has_x;
	}
	
	inline void has_y(const bool &has_y)
	{
		__has_y = has_y;
	}
	
	inline void has_timer(const bool &has_timer)
	{
		__has_timer = has_timer;
	}
	
	inline void has_level(const bool &has_level)
	{
		__has_level = has_level;
	}
	

public:

	Bomb()
	{
		has_x(false);
		has_y(false);
		has_timer(false);
		has_level(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Bomb";
	}
	
	virtual inline const std::string name() const
	{
		return "Bomb";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize x
		s += __has_x;
		if (__has_x)
		{
			unsigned char tmp17 = __x;
			auto tmp18 = reinterpret_cast<char*>(&tmp17);
			s += std::string(tmp18, sizeof(unsigned char));
		}
		
		// serialize y
		s += __has_y;
		if (__has_y)
		{
			unsigned char tmp20 = __y;
			auto tmp21 = reinterpret_cast<char*>(&tmp20);
			s += std::string(tmp21, sizeof(unsigned char));
		}
		
		// serialize timer
		s += __has_timer;
		if (__has_timer)
		{
			unsigned char tmp23 = __timer;
			auto tmp24 = reinterpret_cast<char*>(&tmp23);
			s += std::string(tmp24, sizeof(unsigned char));
		}
		
		// serialize level
		s += __has_level;
		if (__has_level)
		{
			unsigned char tmp26 = __level;
			auto tmp27 = reinterpret_cast<char*>(&tmp26);
			s += std::string(tmp27, sizeof(unsigned char));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize x
		__has_x = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_x)
		{
			__x = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize y
		__has_y = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_y)
		{
			__y = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize timer
		__has_timer = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_timer)
		{
			__timer = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize level
		__has_level = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_level)
		{
			__level = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		return offset;
	}
};


class Explosion : public KSObject
{

protected:

	unsigned char __x;
	unsigned char __y;

	bool __has_x;
	bool __has_y;


public: // getters

	inline unsigned char x() const
	{
		return __x;
	}
	
	inline unsigned char y() const
	{
		return __y;
	}
	

public: // reference getters

	inline unsigned char &ref_x() const
	{
		return (unsigned char&) __x;
	}
	
	inline unsigned char &ref_y() const
	{
		return (unsigned char&) __y;
	}
	

public: // setters

	inline void x(const unsigned char &x)
	{
		__x = x;
		has_x(true);
	}
	
	inline void y(const unsigned char &y)
	{
		__y = y;
		has_y(true);
	}
	

public: // has_attribute getters

	inline bool has_x() const
	{
		return __has_x;
	}
	
	inline bool has_y() const
	{
		return __has_y;
	}
	

public: // has_attribute setters

	inline void has_x(const bool &has_x)
	{
		__has_x = has_x;
	}
	
	inline void has_y(const bool &has_y)
	{
		__has_y = has_y;
	}
	

public:

	Explosion()
	{
		has_x(false);
		has_y(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "Explosion";
	}
	
	virtual inline const std::string name() const
	{
		return "Explosion";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize x
		s += __has_x;
		if (__has_x)
		{
			unsigned char tmp29 = __x;
			auto tmp30 = reinterpret_cast<char*>(&tmp29);
			s += std::string(tmp30, sizeof(unsigned char));
		}
		
		// serialize y
		s += __has_y;
		if (__has_y)
		{
			unsigned char tmp32 = __y;
			auto tmp33 = reinterpret_cast<char*>(&tmp32);
			s += std::string(tmp33, sizeof(unsigned char));
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize x
		__has_x = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_x)
		{
			__x = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		// deserialize y
		__has_y = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_y)
		{
			__y = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
		}
		
		return offset;
	}
};


class World : public KSObject
{

protected:

	std::vector<std::vector<Cell>> __board;
	std::map<std::string, Bomberman> __bombermans;
	std::map<std::string, std::vector<Bomb>> __bombs;
	std::vector<Explosion> __explosions;
	std::vector<unsigned int> __explosion_radiuses;

	bool __has_board;
	bool __has_bombermans;
	bool __has_bombs;
	bool __has_explosions;
	bool __has_explosion_radiuses;


public: // getters

	inline std::vector<std::vector<Cell>> board() const
	{
		return __board;
	}
	
	inline std::map<std::string, Bomberman> bombermans() const
	{
		return __bombermans;
	}
	
	inline std::map<std::string, std::vector<Bomb>> bombs() const
	{
		return __bombs;
	}
	
	inline std::vector<Explosion> explosions() const
	{
		return __explosions;
	}
	
	inline std::vector<unsigned int> explosion_radiuses() const
	{
		return __explosion_radiuses;
	}
	

public: // reference getters

	inline std::vector<std::vector<Cell>> &ref_board() const
	{
		return (std::vector<std::vector<Cell>>&) __board;
	}
	
	inline std::map<std::string, Bomberman> &ref_bombermans() const
	{
		return (std::map<std::string, Bomberman>&) __bombermans;
	}
	
	inline std::map<std::string, std::vector<Bomb>> &ref_bombs() const
	{
		return (std::map<std::string, std::vector<Bomb>>&) __bombs;
	}
	
	inline std::vector<Explosion> &ref_explosions() const
	{
		return (std::vector<Explosion>&) __explosions;
	}
	
	inline std::vector<unsigned int> &ref_explosion_radiuses() const
	{
		return (std::vector<unsigned int>&) __explosion_radiuses;
	}
	

public: // setters

	inline void board(const std::vector<std::vector<Cell>> &board)
	{
		__board = board;
		has_board(true);
	}
	
	inline void bombermans(const std::map<std::string, Bomberman> &bombermans)
	{
		__bombermans = bombermans;
		has_bombermans(true);
	}
	
	inline void bombs(const std::map<std::string, std::vector<Bomb>> &bombs)
	{
		__bombs = bombs;
		has_bombs(true);
	}
	
	inline void explosions(const std::vector<Explosion> &explosions)
	{
		__explosions = explosions;
		has_explosions(true);
	}
	
	inline void explosion_radiuses(const std::vector<unsigned int> &explosion_radiuses)
	{
		__explosion_radiuses = explosion_radiuses;
		has_explosion_radiuses(true);
	}
	

public: // has_attribute getters

	inline bool has_board() const
	{
		return __has_board;
	}
	
	inline bool has_bombermans() const
	{
		return __has_bombermans;
	}
	
	inline bool has_bombs() const
	{
		return __has_bombs;
	}
	
	inline bool has_explosions() const
	{
		return __has_explosions;
	}
	
	inline bool has_explosion_radiuses() const
	{
		return __has_explosion_radiuses;
	}
	

public: // has_attribute setters

	inline void has_board(const bool &has_board)
	{
		__has_board = has_board;
	}
	
	inline void has_bombermans(const bool &has_bombermans)
	{
		__has_bombermans = has_bombermans;
	}
	
	inline void has_bombs(const bool &has_bombs)
	{
		__has_bombs = has_bombs;
	}
	
	inline void has_explosions(const bool &has_explosions)
	{
		__has_explosions = has_explosions;
	}
	
	inline void has_explosion_radiuses(const bool &has_explosion_radiuses)
	{
		__has_explosion_radiuses = has_explosion_radiuses;
	}
	

public:

	World()
	{
		has_board(false);
		has_bombermans(false);
		has_bombs(false);
		has_explosions(false);
		has_explosion_radiuses(false);
	}
	
	static inline const std::string nameStatic()
	{
		return "World";
	}
	
	virtual inline const std::string name() const
	{
		return "World";
	}
	
	std::string serialize() const
	{
		std::string s = "";
		
		// serialize board
		s += __has_board;
		if (__has_board)
		{
			std::string tmp34 = "";
			unsigned int tmp36 = __board.size();
			auto tmp37 = reinterpret_cast<char*>(&tmp36);
			tmp34 += std::string(tmp37, sizeof(unsigned int));
			while (tmp34.size() && tmp34.back() == 0)
				tmp34.pop_back();
			unsigned char tmp39 = tmp34.size();
			auto tmp40 = reinterpret_cast<char*>(&tmp39);
			s += std::string(tmp40, sizeof(unsigned char));
			s += tmp34;
			
			for (auto &tmp41 : __board)
			{
				s += '\x01';
				std::string tmp42 = "";
				unsigned int tmp44 = tmp41.size();
				auto tmp45 = reinterpret_cast<char*>(&tmp44);
				tmp42 += std::string(tmp45, sizeof(unsigned int));
				while (tmp42.size() && tmp42.back() == 0)
					tmp42.pop_back();
				unsigned char tmp47 = tmp42.size();
				auto tmp48 = reinterpret_cast<char*>(&tmp47);
				s += std::string(tmp48, sizeof(unsigned char));
				s += tmp42;
				
				for (auto &tmp49 : tmp41)
				{
					s += '\x01';
					s += tmp49.serialize();
				}
			}
		}
		
		// serialize bombermans
		s += __has_bombermans;
		if (__has_bombermans)
		{
			std::string tmp50 = "";
			unsigned int tmp52 = __bombermans.size();
			auto tmp53 = reinterpret_cast<char*>(&tmp52);
			tmp50 += std::string(tmp53, sizeof(unsigned int));
			while (tmp50.size() && tmp50.back() == 0)
				tmp50.pop_back();
			unsigned char tmp55 = tmp50.size();
			auto tmp56 = reinterpret_cast<char*>(&tmp55);
			s += std::string(tmp56, sizeof(unsigned char));
			s += tmp50;
			
			for (auto &tmp57 : __bombermans)
			{
				s += '\x01';
				std::string tmp58 = "";
				unsigned int tmp60 = tmp57.first.size();
				auto tmp61 = reinterpret_cast<char*>(&tmp60);
				tmp58 += std::string(tmp61, sizeof(unsigned int));
				while (tmp58.size() && tmp58.back() == 0)
					tmp58.pop_back();
				unsigned char tmp63 = tmp58.size();
				auto tmp64 = reinterpret_cast<char*>(&tmp63);
				s += std::string(tmp64, sizeof(unsigned char));
				s += tmp58;
				
				s += tmp57.first;
				
				s += '\x01';
				s += tmp57.second.serialize();
			}
		}
		
		// serialize bombs
		s += __has_bombs;
		if (__has_bombs)
		{
			std::string tmp65 = "";
			unsigned int tmp67 = __bombs.size();
			auto tmp68 = reinterpret_cast<char*>(&tmp67);
			tmp65 += std::string(tmp68, sizeof(unsigned int));
			while (tmp65.size() && tmp65.back() == 0)
				tmp65.pop_back();
			unsigned char tmp70 = tmp65.size();
			auto tmp71 = reinterpret_cast<char*>(&tmp70);
			s += std::string(tmp71, sizeof(unsigned char));
			s += tmp65;
			
			for (auto &tmp72 : __bombs)
			{
				s += '\x01';
				std::string tmp73 = "";
				unsigned int tmp75 = tmp72.first.size();
				auto tmp76 = reinterpret_cast<char*>(&tmp75);
				tmp73 += std::string(tmp76, sizeof(unsigned int));
				while (tmp73.size() && tmp73.back() == 0)
					tmp73.pop_back();
				unsigned char tmp78 = tmp73.size();
				auto tmp79 = reinterpret_cast<char*>(&tmp78);
				s += std::string(tmp79, sizeof(unsigned char));
				s += tmp73;
				
				s += tmp72.first;
				
				s += '\x01';
				std::string tmp80 = "";
				unsigned int tmp82 = tmp72.second.size();
				auto tmp83 = reinterpret_cast<char*>(&tmp82);
				tmp80 += std::string(tmp83, sizeof(unsigned int));
				while (tmp80.size() && tmp80.back() == 0)
					tmp80.pop_back();
				unsigned char tmp85 = tmp80.size();
				auto tmp86 = reinterpret_cast<char*>(&tmp85);
				s += std::string(tmp86, sizeof(unsigned char));
				s += tmp80;
				
				for (auto &tmp87 : tmp72.second)
				{
					s += '\x01';
					s += tmp87.serialize();
				}
			}
		}
		
		// serialize explosions
		s += __has_explosions;
		if (__has_explosions)
		{
			std::string tmp88 = "";
			unsigned int tmp90 = __explosions.size();
			auto tmp91 = reinterpret_cast<char*>(&tmp90);
			tmp88 += std::string(tmp91, sizeof(unsigned int));
			while (tmp88.size() && tmp88.back() == 0)
				tmp88.pop_back();
			unsigned char tmp93 = tmp88.size();
			auto tmp94 = reinterpret_cast<char*>(&tmp93);
			s += std::string(tmp94, sizeof(unsigned char));
			s += tmp88;
			
			for (auto &tmp95 : __explosions)
			{
				s += '\x01';
				s += tmp95.serialize();
			}
		}
		
		// serialize explosion_radiuses
		s += __has_explosion_radiuses;
		if (__has_explosion_radiuses)
		{
			std::string tmp96 = "";
			unsigned int tmp98 = __explosion_radiuses.size();
			auto tmp99 = reinterpret_cast<char*>(&tmp98);
			tmp96 += std::string(tmp99, sizeof(unsigned int));
			while (tmp96.size() && tmp96.back() == 0)
				tmp96.pop_back();
			unsigned char tmp101 = tmp96.size();
			auto tmp102 = reinterpret_cast<char*>(&tmp101);
			s += std::string(tmp102, sizeof(unsigned char));
			s += tmp96;
			
			for (auto &tmp103 : __explosion_radiuses)
			{
				s += '\x01';
				unsigned int tmp105 = tmp103;
				auto tmp106 = reinterpret_cast<char*>(&tmp105);
				s += std::string(tmp106, sizeof(unsigned int));
			}
		}
		
		return s;
	}
	
	unsigned int deserialize(const std::string &s, unsigned int offset=0)
	{
		// deserialize board
		__has_board = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_board)
		{
			unsigned char tmp107;
			tmp107 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp108 = std::string(&s[offset], tmp107);
			offset += tmp107;
			while (tmp108.size() < sizeof(unsigned int))
				tmp108 += '\x00';
			unsigned int tmp109;
			tmp109 = *((unsigned int*) (&tmp108[0]));
			
			__board.clear();
			for (unsigned int tmp110 = 0; tmp110 < tmp109; tmp110++)
			{
				std::vector<Cell> tmp111;
				offset++;
				unsigned char tmp112;
				tmp112 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp113 = std::string(&s[offset], tmp112);
				offset += tmp112;
				while (tmp113.size() < sizeof(unsigned int))
					tmp113 += '\x00';
				unsigned int tmp114;
				tmp114 = *((unsigned int*) (&tmp113[0]));
				
				tmp111.clear();
				for (unsigned int tmp115 = 0; tmp115 < tmp114; tmp115++)
				{
					Cell tmp116;
					offset++;
					offset = tmp116.deserialize(s, offset);
					tmp111.push_back(tmp116);
				}
				__board.push_back(tmp111);
			}
		}
		
		// deserialize bombermans
		__has_bombermans = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_bombermans)
		{
			unsigned char tmp117;
			tmp117 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp118 = std::string(&s[offset], tmp117);
			offset += tmp117;
			while (tmp118.size() < sizeof(unsigned int))
				tmp118 += '\x00';
			unsigned int tmp119;
			tmp119 = *((unsigned int*) (&tmp118[0]));
			
			__bombermans.clear();
			for (unsigned int tmp120 = 0; tmp120 < tmp119; tmp120++)
			{
				std::string tmp121;
				offset++;
				unsigned char tmp123;
				tmp123 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp124 = std::string(&s[offset], tmp123);
				offset += tmp123;
				while (tmp124.size() < sizeof(unsigned int))
					tmp124 += '\x00';
				unsigned int tmp125;
				tmp125 = *((unsigned int*) (&tmp124[0]));
				
				tmp121 = s.substr(offset, tmp125);
				offset += tmp125;
				
				Bomberman tmp122;
				offset++;
				offset = tmp122.deserialize(s, offset);
				
				__bombermans[tmp121] = tmp122;
			}
		}
		
		// deserialize bombs
		__has_bombs = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_bombs)
		{
			unsigned char tmp126;
			tmp126 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp127 = std::string(&s[offset], tmp126);
			offset += tmp126;
			while (tmp127.size() < sizeof(unsigned int))
				tmp127 += '\x00';
			unsigned int tmp128;
			tmp128 = *((unsigned int*) (&tmp127[0]));
			
			__bombs.clear();
			for (unsigned int tmp129 = 0; tmp129 < tmp128; tmp129++)
			{
				std::string tmp130;
				offset++;
				unsigned char tmp132;
				tmp132 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp133 = std::string(&s[offset], tmp132);
				offset += tmp132;
				while (tmp133.size() < sizeof(unsigned int))
					tmp133 += '\x00';
				unsigned int tmp134;
				tmp134 = *((unsigned int*) (&tmp133[0]));
				
				tmp130 = s.substr(offset, tmp134);
				offset += tmp134;
				
				std::vector<Bomb> tmp131;
				offset++;
				unsigned char tmp135;
				tmp135 = *((unsigned char*) (&s[offset]));
				offset += sizeof(unsigned char);
				std::string tmp136 = std::string(&s[offset], tmp135);
				offset += tmp135;
				while (tmp136.size() < sizeof(unsigned int))
					tmp136 += '\x00';
				unsigned int tmp137;
				tmp137 = *((unsigned int*) (&tmp136[0]));
				
				tmp131.clear();
				for (unsigned int tmp138 = 0; tmp138 < tmp137; tmp138++)
				{
					Bomb tmp139;
					offset++;
					offset = tmp139.deserialize(s, offset);
					tmp131.push_back(tmp139);
				}
				
				__bombs[tmp130] = tmp131;
			}
		}
		
		// deserialize explosions
		__has_explosions = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_explosions)
		{
			unsigned char tmp140;
			tmp140 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp141 = std::string(&s[offset], tmp140);
			offset += tmp140;
			while (tmp141.size() < sizeof(unsigned int))
				tmp141 += '\x00';
			unsigned int tmp142;
			tmp142 = *((unsigned int*) (&tmp141[0]));
			
			__explosions.clear();
			for (unsigned int tmp143 = 0; tmp143 < tmp142; tmp143++)
			{
				Explosion tmp144;
				offset++;
				offset = tmp144.deserialize(s, offset);
				__explosions.push_back(tmp144);
			}
		}
		
		// deserialize explosion_radiuses
		__has_explosion_radiuses = *((unsigned char*) (&s[offset]));
		offset += sizeof(unsigned char);
		if (__has_explosion_radiuses)
		{
			unsigned char tmp145;
			tmp145 = *((unsigned char*) (&s[offset]));
			offset += sizeof(unsigned char);
			std::string tmp146 = std::string(&s[offset], tmp145);
			offset += tmp145;
			while (tmp146.size() < sizeof(unsigned int))
				tmp146 += '\x00';
			unsigned int tmp147;
			tmp147 = *((unsigned int*) (&tmp146[0]));
			
			__explosion_radiuses.clear();
			for (unsigned int tmp148 = 0; tmp148 < tmp147; tmp148++)
			{
				unsigned int tmp149;
				offset++;
				tmp149 = *((unsigned int*) (&s[offset]));
				offset += sizeof(unsigned int);
				__explosion_radiuses.push_back(tmp149);
			}
		}
		
		return offset;
	}
};

} // namespace models

} // namespace ks

#endif // _KS_MODELS_H_
