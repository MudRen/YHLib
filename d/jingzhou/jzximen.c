inherit ROOM;

void create()
{
        set("short", "��������" );
        set("long", @LONG
���������ݵ����ţ������������Ǿ���Ҫ�أ���˳�ǽ��
ʵ�ޱȣ���¥�߸��������������ţ���̤���˼��յ������һ
ֱ���츩֮����ȥ��·�϶������裬�����Ҫȥ�Ļ�����ض�
��С�ġ����˳��ţ����뾣�ݣ���͵��ڵ�����ԭ�ˡ�
LONG);
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/ducha" : 1,
        ]));

        set("exits", ([  
               "east" : __DIR__"xidajie2",
               "west" : "/d/city3/shudao1",
        ]));
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}
