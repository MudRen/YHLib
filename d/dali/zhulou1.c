inherit ROOM;

void create()
{
        set("short", "��¥��");
        set("long", @LONG
̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ
������Ϊǽ����¥�����൱���¡��²������ֻ���ĸ����Ӽ�
�յģ��ȿ�������Ȧ��ҲΪ�˷��ߡ�һ������ͨ���ϲ�ķ��ᡣ
LONG);
        set("outdoors", "dali");
        set("exits", ([
                "south" : __DIR__"wuding",
                "up"    : __DIR__"zhulou2",
        ]));
        setup();
        replace_program(ROOM);
}
