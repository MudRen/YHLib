inherit ROOM;

void create()
{
	set("short", "�񶼵�");
	set("long", @LONG
�������񶼴����������������ٳǡ��򶫾Ϳ��Ե��ᶽ
���ˡ�ƽͷ�������ˣ�·�ϴ������ͷ������ү�ǡ������ٱ�
������״����Ź������ˡ�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    	"west"  : __DIR__"westroad2",
	    	"east"  : __DIR__"guangchang",
	]));

	set("objects", ([
	    	"/d/city/npc/bing" : 2,
	]));

	setup();
	replace_program(ROOM);
}
