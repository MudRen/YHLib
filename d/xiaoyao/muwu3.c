inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����Ҳ��һ��ľ�ݣ������еİ���ʲô�򵥣�����ȴ�к�
�๤�ߣ��������������������������������ص�ľм��һ����
֪����һ�������ļҡ�
LONG);
        set("exits", ([
                "north" : __DIR__"mubanlu",
        ]));
        set("objects", ([
                CLASS_D("xiaoyao") + "/fengas" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
