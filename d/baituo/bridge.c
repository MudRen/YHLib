inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ��С���ţ�����ɽ�ϵı�ѩ�ڻ��γ�һ���峺��С
Ϫ�������»�����������ʱ����Ƥ��С��Ծ��ˮ�棬��������
����һ������ɫ�Ļ��ߡ�
LONG);
        set("outdoors", "baituo");
        set("exits", ([
                "north" : __DIR__"guangchang",
                "east"  : __DIR__"xijie",
        ]));
        set("objects",([
                __DIR__"npc/cungu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
