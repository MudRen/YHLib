inherit  ROOM;

void  create  ()
{
        set("short",  "�����");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮��
�����ݣ�������ֱ�������ǡ�
LONG);
        set("exits",  ([
                "east"  :  __DIR__"road7",
                "west"  :  __DIR__"road5",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
