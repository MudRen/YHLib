// edit.c
// updated by doing

inherit F_CLEAN_UP;

int main(object me, string file)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        if (! file)
                return notify_fail("ָ���ʽ��edit <����>\n");

        if (! me->is_admin())
        {
                switch (SECURITY_D->query_site_privilege("edit"))
                {
                case "all":
                        break;

                default:
                        return notify_fail("�㲻�ܱ༭����ļ���\n");
                }
        }

        if (in_edit(me))
                return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), file);
        me->set("cwf", file);
        me->edit_file(file);
        log_file("static/edit", sprintf("%s %-9s edit %s from %s.\n",
                                        log_time(),
                                        geteuid(me), file,
                                        query_ip_name(me)));
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������

�������ڿ��Ա���Ȩʹ�õ���Ϣ������enable��
HELP );
        return 1;
}

