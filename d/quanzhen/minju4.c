inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���������һ�����Ϳ����ݽǴ��С���ض�������ʳ����
�ó���������ճ�ȷʵ������������һλ������Ц������
�����Լ��Ļ�����Ҳ������������������ֲ����ˡ�
LONG);
        set("exits", ([
                "northeast" : __DIR__"guchang",
        ]));

        set("objects", ([
                __DIR__"npc/cunmin" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
