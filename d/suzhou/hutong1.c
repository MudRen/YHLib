inherit ROOM;

void create()
{
        set("short", "��ͬ");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ�����
����Ϣ��������ͨ��С��������˾��ӵ�Ȼ�ǲ������Ǳ���
ȥ�ġ������߾ͻ�ص����д�·�ˡ�
LONG );
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("exits", ([
                "south"     : __DIR__"dongdajie1",
                "northeast" : __DIR__"hutong2",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

