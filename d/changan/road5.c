inherit  ROOM;

void  create  ()
{
        set("short",  "�����");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮��
�����ݣ�������ֱ�������ǡ�
LONG);
        set("exits",  ([
                "east"  :  __DIR__"road6",
                "west"  :  __DIR__"road1",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
