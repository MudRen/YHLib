inherit BUILD_ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����̨�����������ڣ����ɲ������գ���Ϊ������ǣ�ÿ������
�죬ɽ��֮�о��������������֡���Ŀ�������羰�续������������
��طǳ���⡣
LONG);
        set("outdoors", "huashan");
        set("exits",([ /* sizeof() == 1 */
            "eastdown": __DIR__"chaopath2",
        ]));
        set("max_room", 3);
        setup();
        replace_program(ROOM);
}
