inherit ROOM;
 
void create()
{
        set("short", "�������᷿");
        set("long",@LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ��
��ľ���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż�
���ֻ����õ�һ�߰��ż��Ŵ󴲣����˿��˾���˯����
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([
            	"west"   : __DIR__"tian1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi6" : 1,
        ]));       
        setup();
        replace_program(ROOM);
}
