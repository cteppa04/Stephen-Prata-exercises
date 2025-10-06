#ifndef TVFM_H_
#define TVFM_H_

class Remote
{
public:
	friend class Tv;
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cabel };
	enum { TV, DVD };
	enum Rmode { Normal, Interactive };
private:
	int mode;
	int rmode;
public:
	Remote(int m = TV, int rm = Normal) : mode(m), rmode(rm) {};
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_mode(Tv& t);
	void set_input(Tv& t);
	void set_chan(Tv& t, int c);
	void show_mode() const;
};

class Tv
{
public:
	friend class Remote;
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cabel };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(125), channel(2), mode(Cabel), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cabel : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	bool change_rmode(Remote& r);
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

inline bool Remote::volup(Tv& t) { return t.volup(); }
inline bool Remote::voldown(Tv& t) { return t.voldown(); }
inline void Remote::onoff(Tv& t) { t.onoff(); }
inline void Remote::chanup(Tv& t) { t.chanup(); }
inline void Remote::chandown(Tv& t) { t.chandown(); }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }
inline void Remote::set_chan(Tv& t, int c) { t.channel = c; }

#endif // !TVFM_H_
