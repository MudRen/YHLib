inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������һ����������Ĵ�����ϡ���������������������
�ġ����̵ġ����Ŵ󳵵�����Ͼ��Ͽ�������������������
�����֡���ʱ����������������߷ɳ۶���������һ·������
��·��������������������֡����߾��Ǵ�֮���ˡ�
LONG );
        set("exits", ([
                "east"  : "/b/tulong/haigang",
                "south" : "/d/shaolin/ruzhou",
                "north" : __DIR__"road9",
        ]));
        set("objects",([
                "/d/taishan/npc/tiao-fu" : 1,
        ]));
        set("outdoors", "beijing");
        setup();
        replace_program(ROOM);
}

