inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ������Ķ��ˣ�������Ũ�ܵ�֦Ҷ��ʪ������̦޺��
ͻȻ��һ��΢�紵������Ҷ���������������������������ȥ
��ֻ����һ�����Σ����뻹�ǸϿ���ȥ�ɡ�
LONG);
        set("outdoors", "wudujiao");
        set("exits", ([
                "down" : __DIR__"nanyuan",
        ]));
        set("objects", ([
                  __DIR__"obj/xiang": 1,
        ]));
        setup();
        replace_program(ROOM);
}
