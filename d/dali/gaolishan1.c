inherit ROOM;

void create()
{
        set("short", "����ɽ����");
        set("long", @LONG
�����Ǹ���ɽ�Ķ��£��򶫸��ӱ��ʶ����Ķ���ˮ��ԶԶ
���������Եı���ѩɽ����ȥ������ȫ�ǳ�ɽ���룬����ϡ
�١�ɽ�������޶࣬����������˾�����ɽ���ԡ�
LONG);
        set("objects", ([
                "/clone/quarry/yang2" : 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "west"     : __DIR__"gaolishan2",
                "eastdown" : __DIR__"atoubu",
        ]));
        setup();
        replace_program(ROOM);
}
