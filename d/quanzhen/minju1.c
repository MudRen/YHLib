inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������һ�������ʵ��С���˼ң�����������ש������
�����׺�ľ���Ρ�ǽ�Ϲ��ż���ɽˮ�������˲��ڼ��
LONG);
        set("exits", ([
                "east" : __DIR__"beijie",
        ]));
        setup();
        replace_program(ROOM);
}
