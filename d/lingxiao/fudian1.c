inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ǵĸ���֮һ��ѩɽ��������ӣ������Ű�����
�⣬������֧����֧����Լ���ϵ����ʲô�£����ֲ����ᵽȫ
�ɽ���ģ��������ڸ������顣
LONG);
        set("exits",([
            	"west"  : __DIR__"lianwu1",
            	"east"  : __DIR__"dadian",
        ]));
        set("objects", ([
               __DIR__"npc/dizi" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

