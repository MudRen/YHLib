inherit  ROOM;

void  create  ()
{
        set("short",  "�����");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮��
�����ݣ�������ֱ�������ǡ�
LONG);
        set("exits",  ([
                "east"  :  "/d/city/ximenroad",
                "west"  :  __DIR__"road7",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
