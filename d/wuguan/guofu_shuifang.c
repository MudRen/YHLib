inherit ROOM;

void create()
{
    set("short", "ˮ��");
    set("long", @LONG
һ���ݣ��㿴�����ڷ��ż��ڴ�ף�������װˮ�õģ���
�����ƺ����ǿյģ�����û��һ���ˣ��������˶����ˡ�
LONG);
        set("no_fight", 1);
        set("exits", ([
             	"east" : __DIR__"guofu_houyuan",
        ]) );
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
