inherit ROOM;

void create()
{
        set("short", "������Ⱥ��");
        set("long", @LONG
�����һƬ����������������˵�����һ���ļ��ڲ�ԭ
�϶����ϱ���Ǩ�ơ�����һ����ǰ����һ�Ŵ���Ƥ�Եø�����
Ŀ��һ�����������Ů�����˾ƽ��������ܿ������к��㡣
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
            	"south" : __DIR__"huijiang5",
        ]));
        set("objects", ([
                __DIR__"npc/aman"  : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
